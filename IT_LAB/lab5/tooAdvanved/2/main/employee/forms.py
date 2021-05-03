from django.forms import ModelForm, DateInput
from .models import Employee


class EmployeeForm(ModelForm):
    class Meta:
        model = Employee
        fields = '__all__'
        widgets = {
            'date_of_joining': DateInput(attrs={'type': 'date'})
        }
