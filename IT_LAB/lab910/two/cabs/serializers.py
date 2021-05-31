from rest_framework import serializers
from .models import Cabs

class CabsSerializer(serializers.ModelSerializer):
    class Meta:
        model = Cabs
        fields = '__all__'
