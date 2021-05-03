from django.forms import ModelForm, DateInput
from .models import Calculator


class CalculatorForm(ModelForm):
    class Meta:
        model = Calculator
        fields = '__all__'
