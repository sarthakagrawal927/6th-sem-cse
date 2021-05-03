from django.db import models
from django.utils.translation import gettext_lazy as _

class Calculator(models.Model):
    class Operation(models.TextChoices):
        ADD = '+', _('add')
        SUBTRACT = '-', _('subtract')
        MULTIPLY = '*', _('multiply')
        DIVIDE = '/', _('divide')

    number_1 = models.DecimalField(max_digits=5, decimal_places=2)
    number_2 = models.DecimalField(max_digits=5, decimal_places=2)
    operation = models.CharField(
        max_length=1,
        choices=Operation.choices,
        default=Operation.ADD,
    )
