char *strdup(const char *str)
{
	size_t len = strlen(str);
	char *new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);

	strcpy(new_str,_ str);
	return (new_str);
}
