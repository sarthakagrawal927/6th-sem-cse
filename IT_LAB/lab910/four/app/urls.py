from django.urls import path
from .views import HotelList, HotelDetail, FlowerList, FlowerDetail, MedicineList, MedicineDetail, LocationDetail, LocationList

urlpatterns = [
    path('hotel/', HotelList.as_view()),
    path('hotel/<int:pk>/', HotelDetail.as_view()),

    path('flower/', FlowerList.as_view()),
    path('flower/<int:pk>/', FlowerDetail.as_view()),

    path('medicine/', MedicineList.as_view()),
    path('medicine/<int:pk>/', MedicineDetail.as_view()),

    path('location/', LocationList.as_view()),
    path('location/<int:pk>/', LocationDetail.as_view())
]
