from django.db import models
from django.utils.translation import gettext_lazy as _


class Employee(models.Model):
    class EmployeeIds(models.TextChoices):
        id_1 = 'id_1', _('id_1')
        id_2 = 'id_2', _('id_2')
        id_3 = 'id_3', _('id_3')
        id_4 = 'id_4', _('id_4')

    date_of_joining = models.DateField()
    employee_id = models.CharField(
        max_length=4,
        choices=EmployeeIds.choices,
        default=EmployeeIds.id_1,
    )
