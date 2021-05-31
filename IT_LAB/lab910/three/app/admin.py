from django.contrib import admin
from .models import Restaurant, Cuisine, City

models = [Restaurant, Cuisine, City]
admin.site.register(models)
