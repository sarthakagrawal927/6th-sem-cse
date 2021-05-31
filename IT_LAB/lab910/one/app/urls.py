from django.urls import path
from .views import UserList, UserDetail, BlogList, BlogDetail, CommentList, CommentDetail

urlpatterns = [
    path('user/', UserList.as_view()),
    path('user/<int:pk>/', UserDetail.as_view()),

    path('blog/', BlogList.as_view()),
    path('blog/<int:pk>/', BlogDetail.as_view()),

    path('comment/', CommentList.as_view()),
    path('comment/<int:pk>/', CommentDetail.as_view())
]
