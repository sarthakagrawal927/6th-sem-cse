from rest_framework import generics
from .serializers import HotelSerializer, FlowerSerializer, MedicineSerializer, LocationSerializer
from .models import Hotel, Flower, Medicine, Location


class HotelList(generics.ListCreateAPIView):
    # queryset = Hotel.objects.all()
    serializer_class = HotelSerializer

    def get_queryset(self):
        queryset = Hotel.objects.all()
        location = self.request.query_params.get('location')
        if location is not None:
            queryset = queryset.filter(location__name=location)
        name = self.request.query_params.get('name')
        if name is not None:
            queryset = queryset.filter(name=name)
        return queryset


class HotelDetail(generics.RetrieveUpdateDestroyAPIView):
    queryset = Hotel.objects.all()
    serializer_class = HotelSerializer


class FlowerList(generics.ListCreateAPIView):
    # queryset = Flower.objects.all()
    serializer_class = FlowerSerializer

    def get_queryset(self):
        queryset = Flower.objects.all()
        location = self.request.query_params.get('location')
        if location is not None:
            queryset = queryset.filter(location__name=location)
        name = self.request.query_params.get('name')
        if name is not None:
            queryset = queryset.filter(name=name)
        return queryset


class FlowerDetail(generics.RetrieveUpdateDestroyAPIView):
    queryset = Flower.objects.all()
    serializer_class = FlowerSerializer


class MedicineList(generics.ListCreateAPIView):
    # queryset = Medicine.objects.all()
    serializer_class = MedicineSerializer

    def get_queryset(self):
        queryset = Medicine.objects.all()
        location = self.request.query_params.get('location')
        if location is not None:
            queryset = queryset.filter(location__name=location)
        name = self.request.query_params.get('name')
        if name is not None:
            queryset = queryset.filter(name=name)
        return queryset


class MedicineDetail(generics.RetrieveUpdateDestroyAPIView):
    queryset = Medicine.objects.all()
    serializer_class = MedicineSerializer


class LocationList(generics.ListCreateAPIView):
    queryset = Location.objects.all()
    serializer_class = LocationSerializer


class LocationDetail(generics.RetrieveUpdateDestroyAPIView):
    queryset = Location.objects.all()
    serializer_class = LocationSerializer
