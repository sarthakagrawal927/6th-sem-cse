from rest_framework import generics
from .serializers import CitySerializer, RestaurantSerializer, CuisineSerializer
from .models import City, Restaurant, Cuisine


class CityList(generics.ListCreateAPIView):
    queryset = City.objects.all()
    serializer_class = CitySerializer


class CityDetail(generics.RetrieveUpdateDestroyAPIView):
    queryset = City.objects.all()
    serializer_class = CitySerializer


class RestaurantList(generics.ListCreateAPIView):

    # queryset = Restaurant.objects.all()
    serializer_class = RestaurantSerializer

    def get_queryset(self):
        queryset = Restaurant.objects.all()
        city = self.request.query_params.get('city')
        if city is not None:
            queryset = queryset.filter(city__name=city)
        cuisine = self.request.query_params.get('cuisine')
        if cuisine is not None:
            queryset = queryset.filter(cuisine__name=cuisine)
        name = self.request.query_params.get('name')
        if name is not None:
            queryset = queryset.filter(name=name)
        return queryset


class RestaurantDetail(generics.RetrieveUpdateDestroyAPIView):
    queryset = Restaurant.objects.all()
    serializer_class = RestaurantSerializer


class CuisineList(generics.ListCreateAPIView):
    queryset = Cuisine.objects.all()
    serializer_class = CuisineSerializer


class CuisineDetail(generics.RetrieveUpdateDestroyAPIView):
    queryset = Cuisine.objects.all()
    serializer_class = CuisineSerializer
