
animal_list = [
    "giraffe",
    "dog",
    "cat",
    "penguin",
    "flamingo",
    "owl" 
    ]

animal = "giraffe"

def feed(food):
    return food

if animal == "penguin":
    feed("fish")
elif animal == "giraffe":
    feed("leaves") 
elif animal == "flamingo":
    feed("shrimp")
    
    
    

  
match animal : 
    case "giraffe" :
        feed("leaves")
        
    case "penguin"  :
        feed("fish")
        
    case "flamingo":
        feed("shrimp")
        
    case _:
        feed("Default") 

 
        









        
        
        
        
        
        
        
        
        
        
        
def http_error(status):
    match status:
        case 400:
            return "Bad request"
        case 401:
            return "Unauthorized"
        case 402:
            return "Payment Required"
        case 403:
            return "Forbidden"
        case 404:
            return "Not Found"
        case 405:
            return "Method Not Allowed"
        case 406:
            return "Not Acceptable"
        case _:
            return "Default"
    
    
    

    
    

    
