def dec2bin(number)
	number = Integer(number)
	if(number == 0)
		n = "00000000"
		return n
	end
	        
	ret_bin = ""
	while(number != 0)
	    ret_bin = String(number % 2) + ret_bin
	    number = number / 2
	end
	ret_bin
end

def frac2bin(frac)
		z = 23
		result = Float(frac)
		bFrac = ""
		while(z > 0)    
	        result = result*2
	          if(result >= 1)
	            bFrac = String(1)+bFrac
	            result = result - 1
	          elsif (result < 1)
	            bFrac = String(0)+bFrac
	          end
	        z = z-1
	    end
	  return bFrac
end  

def expoent(numero)
    num = 0
    check = 0
    intIs = Integer(numero)
    temp = Float(numero)
    excesso = 127
    expoent = 0
       
    if(temp > 2)
        while(num != 1)
          temp = temp/2
          check = Integer(temp)
          if(check == 1)
              num = 1
          end      
          expoent = expoent+1  
        end      
    elsif(intIs == 1)
        temp = temp -1
        return excesso,temp
    elsif((intIs == 0))
          return 0,temp       
    elsif(temp < -2)
        while(num != 1)
        temp = temp*2
        check = Integer(temp)
        	if(check == 1)
            	num = 1
        	end	      
        	  expoent = expoent-1    
        end  
    else
    	return 0,0
    end	
    return expoent+excesso,(temp-1)       
end




class Teste
	sinal = 3
	z = 0
	frac = 0.0
	expoente = 0
	fractmp = 0.0
	intpart = 0 
	while(z != 1)
		puts "Informe o numero pra converter"
		c = gets
		if(c == "sair\n") 
			break 
		end
		frac = Float(c)
		if (frac < 0)
                sinal = 1
                frac = (frac*(-1))   
        else 
            sinal = 0
        end        
        expoent,fractmp = expoent(frac)
        expoente = dec2bin(expoent)

        fracexp = frac2bin(fractmp)
        
        puts "#{sinal} #{expoente}"+" "+String(fracexp).reverse		
        





	end
end
