from django.urls import path
from .views import CityList, CityDetail, RestaurantList, RestaurantDetail, CuisineList, CuisineDetail

urlpatterns = [
    path('city/', CityList.as_view()),
    path('city/<int:pk>/', CityDetail.as_view()),

    path('restaurant/', RestaurantList.as_view()),
    path('restaurant/<int:pk>/', RestaurantDetail.as_view()),

    path('cuisine/', CuisineList.as_view()),
    path('cuisine/<int:pk>/', CuisineDetail.as_view())
]
