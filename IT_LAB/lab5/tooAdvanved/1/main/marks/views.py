from django.shortcuts import render, redirect
from .forms import StudentForm
from .models import Student


def marks(request):
    form = StudentForm()
    if request.method == 'POST':
        form = StudentForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('marks')
    students = Student.objects.all()
    for student in students:
        student.percentage = (
            student.english_marks + student.physics_marks + student.chemistry_marks
        ) / 300 * 100
    context = {
        'form': form,
        'students': students
    }
    return render(request, 'marks/index.html', context)
