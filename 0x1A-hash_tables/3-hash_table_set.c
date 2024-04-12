/*
 * File: 3-hash_table_set.c
 * Author: Olorundamisi Dunmade <github.com/olorundamisi>
 */

#include "hash_tables.h"

/**
 * hash_table_set - Adds/updates/sets an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: If an error occurs or procedure fails - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;

	char *val_cpy;
	unsigned long int index, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	val_cpy = strdup(value);
	if (val_cpy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = val_cpy;
			return (1); } }

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(val_cpy);
		return (0); }

	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0); }

	new->value = val_cpy;
	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
