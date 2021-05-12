int         option_excute(char **buf, t_option *option, size_t len)
{
    char c;
    c = option_withzero(option);
    if ((int)len > option->prec)
        option->prec = (int)len;
    option->width -= option->prec;
    if (!( option->flag & (LEFT + ZERO)))
        while (option->width-- > 0)
            bufchar_isrt(buf, option, ' '); //write ' '
    if (option->flag & SIGN)
        bufchar_isrt(buf, option, '-'); //write '-'
    if (!(option->flag & LEFT))
        while (option->width-- > 0)
            bufchar_isrt(buf, option, c);// write '0' or ' '
    while ((int)len < option->prec--)
        bufchar_isrt(buf, option, '0'); //write '0'
    return (option->width);
}
char                option_withzero(t_option *option)
{
    char c;
    if (option->flag & LEFT)
        option->flag &= ~ZERO;
    if ((option->prec > 0 && option->width != -1) || option->precflag)
        option->flag &= ~ZERO;
    c = (option->flag & ZERO) ? '0' : ' ';
    return (c);
}
