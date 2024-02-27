#include "shell.h"

/**
 * _strdup - strdup the given string.
 * @str: the string to be strdup.
 * Return: the new string with the given string replaced.
*/
char *_strdup(const char *str)
{
	char *pointer;
	int i = 0, len;

	if (str == NULL)
	{
		return (NULL);
	}

	len = strlen(str);

	pointer = malloc(len + 1);
	if (pointer == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		pointer[i] = str[i];
		i++;
	}
	pointer[len] = '\0';
	return (pointer);
}

/**
 * _strcmp - strcmp function for strings.
 * @str1: the first string to compare.
 * @str2: the second string to compare.
 * Return: strcmp function.
*/
char _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
	{
		i++;
	}
	return ((int)str1[i] - (int)(str2[i]));
}

/**
 * _strlen - function to return the length of the string.
 * @s: the string to be strlen.
 * Return: the length of the string.
*/
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
	{
	}

	return (len);
}

/**
 * _strcat - Concatenate a string into a single string.
 * @d: The string to concatenate.
 * @src: The source string to concatenate.
 * Return: The concatenated string.
*/
char *_strcat(char *d, const char *src)
{
	size_t len = strlen(d);
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		d[len + i] = src[i];
	}

	d[len + i] = '\0';

	return (d);
}

/**
 * _strcpy - function to convert a string to a string.
 * @d: destination string to be converted
 * @src: source string to be converted
 * Return: destination string.
 */
char *_strcpy(char *d, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		d[i] = src[i];
	}

	d[i] = '\0';

	return (d);
}
