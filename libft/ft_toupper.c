char ft_toupper(int c)
{
  if(ft_islower(c))
    c -= 32;
  return c;
}
