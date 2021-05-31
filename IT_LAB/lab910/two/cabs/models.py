from django.db import models


class Cabs(models.Model):
    current_latitude = models.FloatField()
    current_longitude = models.FloatField()

    def __str__(self):
        return "{} {}".format(self.current_latitude, self.current_longitude)
