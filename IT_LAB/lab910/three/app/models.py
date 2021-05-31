from django.db import models


class City(models.Model):
    name = models.CharField(max_length=50)

    def __str__(self):
        return self.name


class Restaurant(models.Model):
    name = models.CharField(max_length=50)
    city = models.ForeignKey(City, on_delete=models.CASCADE)

    def __str__(self):
        return '{} in {}'.format(self.name, self.city)


class Cuisine(models.Model):
    name = models.CharField(max_length=50)
    restaurant = models.ForeignKey(Restaurant, on_delete=models.CASCADE)
    rating = models.CharField(max_length=50)

    def __str__(self):
        return '{} for {}'.format(self.rating, self.restaurant, self.rating)
