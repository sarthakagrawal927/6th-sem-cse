from django.http import JsonResponse
from .converter import converter
from rest_framework.decorators import api_view
from django.shortcuts import render
from .models import Cabs
from .serializers import CabsSerializer
from rest_framework import generics


TIME_PER_KM = 5
FARE_PER_KM = 20


class CabsList(generics.ListCreateAPIView):
    queryset = Cabs.objects.all()
    serializer_class = CabsSerializer

    def get(self, request, *args, **kwargs):
        latitude = request.GET.get('latitude')
        longitude = request.GET.get('longitude')

        if not(latitude) or not(longitude):
            return super().get(request, *args, **kwargs)

        result = []
        for cab in self.queryset.all():
            distance_in_km = converter(
                float(latitude), float(longitude), cab.current_latitude, cab.current_longitude)
            val = {
                'Fare details': '{} kms'.format(distance_in_km * FARE_PER_KM),
                'Estimated time of arrival (ETA)': '{} minutes'.format(distance_in_km * TIME_PER_KM)
            }
            result.append(val)

        return JsonResponse({
            'result': result
        })


class CabsDetail(generics.RetrieveUpdateDestroyAPIView):
    queryset = Cabs.objects.all()
    serializer_class = CabsSerializer


