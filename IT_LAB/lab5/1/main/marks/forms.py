from django.forms import ModelForm, DateInput
from .models import Student


class StudentForm(ModelForm):
    class Meta:
        model = Student
        fields = '__all__'
        widgets = {
            'date_of_birth': DateInput(attrs={'type': 'date'})
        }
