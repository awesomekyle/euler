is_multiple_of value 0 = False
is_multiple_of value multiple = mod value multiple == 0

multiple_of_3_or_5 value = (is_multiple_of value 3) || (is_multiple_of value 5)

count_multiple value =
    if multiple_of_3_or_5 value then value
    else 0

adder 0 = 0
adder max = count_multiple max + adder (max - 1)

main = do print (adder 999)