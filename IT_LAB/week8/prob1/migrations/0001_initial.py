# Generated by Django 3.2 on 2021-05-24 08:07

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Category',
            fields=[
                ('name', models.CharField(max_length=100, primary_key=True, serialize=False)),
                ('numberOfVisits', models.IntegerField()),
                ('numberOfLikes', models.IntegerField()),
            ],
        ),
        migrations.CreateModel(
            name='Page',
            fields=[
                ('category', models.CharField(max_length=100)),
                ('title', models.CharField(max_length=100)),
                ('url', models.URLField(primary_key=True, serialize=False)),
                ('view', models.IntegerField()),
            ],
        ),
    ]
