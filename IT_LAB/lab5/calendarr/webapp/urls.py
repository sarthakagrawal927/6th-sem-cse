from . import views
from django.urls import path, re_path

urlpatterns = [
    path('calculate/', views.calculate, name='calculate'),
    path('marks/', views.marks, name='marks'),
    path('emp/', views.emp, name='emp'),
    path('mag/', views.mag, name='mag'),
    path('cap/', views.cap, name='cap'),
    path('metadata/', views.book, name='book'),
    path('', views.index, name='index'),
    re_path(
        r'^(?P<year>[0-9]{4})/(?P<month>0?[1-9]|1[0-2])/', views.index, name='index')
]
