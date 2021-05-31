from django.contrib import admin
from .models import User, Blog, Comment

models = [User, Blog, Comment]

admin.site.register(models)

