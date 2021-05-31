from django.db import models


class User(models.Model):
    email = models.EmailField(max_length=50)
    phone_number = models.CharField(max_length=50)

    def __str__(self):
        return self.email


class Blog(models.Model):
    title = models.CharField(max_length=50)
    content = models.CharField(max_length=100)
    owner = models.ForeignKey(User, on_delete=models.CASCADE) 

    def __str__(self):
        return self.title


class Comment(models.Model):
    name = models.CharField(max_length=50)
    blog = models.ForeignKey(Blog, on_delete=models.CASCADE)
    owner = models.ForeignKey(User, on_delete=models.CASCADE)

    def __str__(self):
        return self.name
