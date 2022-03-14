def init_matamikya(file_name, matamikya):
    with open(file_name, "r") as matamikya_file:
        for line in matamikya_file:
            line = line.replace(",", '')
            line_list = line.split()

            if (line_list[0] == "add"):
                name = line_list[2]
                price = float(line_list[3])
                amount = float(line_list[4])

                if (name in matamikya.keys()) or (price < 0) or (amount < 0):
                    continue
                else:
                    sales = 0
                    matamikya[name] = [price, amount, sales]
            
            elif (line_list[0] == "change"):
                name = line_list[2]
                new_amount = float(line_list[3])

                if(name in matamikya.keys()):
                    matamikya[name][1] += new_amount
                
            else:
                orders_to_ship = []

                for i in range(2, len(line_list), 3):
                    name = line_list[i]
                    amount_to_ship = float(line_list[i+1])

                    if name in matamikya.keys() and  matamikya[name][1] > 0 and amount_to_ship >= 0:
                        if amount_to_ship <= matamikya[name][1]:
                            price = matamikya[name][0]
                            
                            matamikya[name][1] -= amount_to_ship
                            matamikya[name][2] += amount_to_ship*price

                        


def find_best_selling_product(file_name):
    matamikya = {}
    init_matamikya(file_name, matamikya)

    if len(matamikya) == 0:
        return ("", 0)

    names_list = list( matamikya.keys() ) 
    names_list.sort()

    first_product_name = (tuple((matamikya.keys())))[0]
    max_product = matamikya[ first_product_name ]
    max_name = first_product_name

    for name in names_list:
        if( matamikya[name][2] > max_product[2] ):
            max_product = matamikya[name]
            max_name = name

    max_sales = max_product[2]

    return (max_name, max_sales)
    

    # matamikya = dict( sorted(matamikya.items(), key = lambda x:x[0]) )

    # max_product = max(matamikya.items() , key = (lambda x:x[1][2]) )
    # max_name = max_product[0]
    # max_sales = max_product[1][2]

    # return (max_name, max_sales)
    


def find_k_most_expensive_products(file_name, k):
    
    matamikya = {}
    init_matamikya(file_name,matamikya)
    if k <= 0 or len(matamikya) == 0:
        return []
    
    output_list =[]

    names_and_prices = []
    for name, data in matamikya.items() :
        names_and_prices.append( (name, data[0]) )
    
    names_and_prices = sorted(names_and_prices, key = (lambda x:x[0]) )

    how_much_to_run = min( k,len(matamikya) ) #for the case that k > len(matamikya)

    for i in range(how_much_to_run): 
        current_max = max(names_and_prices , key = (lambda x:x[1]) )
        output_list.append( current_max[0] )
        names_and_prices.remove(current_max)

    return output_list



    # names_list = list( matamikya.keys() ) 
    # names_list.sort()


    # for i in range(how_much_to_run): 
    #      current_max = max(matamikya.items() , key = (lambda x:x[1][0]) )
    #      current_max_price = current_max[1][0]
    #      current_max_name = current_max[0]

    #      for name in names_list:
    #          if matamikya[name][0] == current_max_price:
    #               output_list.append(name)
    #               del matamikya[name]
    #               i+=1




        







        




           
    
    

                    

                    





