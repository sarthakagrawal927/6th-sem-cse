from rest_framework import serializers
from .models import Hotel, Flower, Medicine, Location


class HotelSerializer(serializers.ModelSerializer):
    class Meta:
        model = Hotel
        fields = '__all__'


class FlowerSerializer(serializers.ModelSerializer):
    class Meta:
        model = Flower
        fields = '__all__'


class MedicineSerializer(serializers.ModelSerializer):
    class Meta:
        model = Medicine
        fields = '__all__'


class LocationSerializer(serializers.ModelSerializer):
    class Meta:
        model = Location
        fields = '__all__'
