from django.db import models

# Create your models here.


class Student(models.Model):
    name = models.CharField(max_length=100)
    date_of_birth = models.DateField()
    address = models.CharField(max_length=100)
    contact_number = models.CharField(max_length=100)
    email_id = models.EmailField()
    english_marks = models.IntegerField()
    physics_marks = models.IntegerField()
    chemistry_marks = models.IntegerField()
