int count_char (char *s, char c)
{
  int i = 0;
  int count = 0;

  while (s[i])
  {
    if (s[i] == c)
      count++;
    i++;
  }
  return (count);
}

bool  close_follows_wrong_open(char *s)
{
  int i = 0;

  while (s[i])
  {
    if ((s[i] == '(') && ((s[i + 1] == '}') || (s[i + 1] == ']')))
      return (true);
    if ((s[i] == '{') && ((s[i + 1] == ']') || (s[i + 1] == ']')))
      return (true);
    if ((s[i] == '[') && ((s[i + 1] == '}') || (s[i + 1] == ')')))
      return (true);
    i++;
  }
  return (false);
}

bool nest_is_invalid (char *s, int i, int j)
{
  while ((s[j]) && (i > -1) && ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) && ((s[j] == ')') || (s[j] == ']') || (s[j] == ')')))
  {
    if ((s[i] == '(') && (s[j] != ')'))
      return (true);
    if ((s[i] == '[') && (s[j] != ']'))
      return (true);
    if ((s[i] == '{') && (s[j] != '}'))
      return (true);
    i--;
    j++;
  }
  return (false);
}

bool isValid(char * s)
{
  if ((count_char(s, '(') != count_char(s, ')')) || (count_char(s, '[') != count_char(s, ']')) || (count_char(s, '{') != count_char(s, '}')))
    return (false);
  if (close_follows_wrong_open(s))
    return (false);
  int i = 0;
  while (s[i])
  {
    if (((s[i] == '(') && (s[i + 1] == ')')) || ((s[i] == '[') && (s[i + 1] == ']')) || ((s[i] == '{') && (s[i + 1] == '}')))
      if (nest_is_invalid(s, i, i + 1))
        return (false);
    i++;
  }
  if ((s[i - 1] != '}') && (s[i - 1] != ']') && (s[i - 1] != ')'))
    return (false);

  return (true);
}