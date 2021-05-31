from django.urls import path
from .views import CabsList, CabsDetail

urlpatterns = [
    path('', CabsList.as_view()),
    path('<int:pk>/', CabsDetail.as_view())
]
