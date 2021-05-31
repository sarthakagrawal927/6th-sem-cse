from django.contrib import admin
from .models import Location, Hotel, Flower, Medicine

models = [Location, Hotel, Flower, Medicine]

admin.site.register(models)
