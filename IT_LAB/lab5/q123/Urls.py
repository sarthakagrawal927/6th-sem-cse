from . import views
from django.urls import path, re_path
urlpatterns = [
    path('calculate/', views.add, name='calculate'),
    path('marks/', views.marks, name='marks'),
    path('emp/', views.emp, name='emp'),
]
