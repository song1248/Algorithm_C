from collections import defaultdict

tc = int(input())
while tc:
    
    matrix_num = int(input())
    pqr = list(map(int,input().split()))
    
    
    M_dict = defaultdict(list)
    matrix_list = []
    for i in range(matrix_num):
        M_dict[i+1] = [pqr[i],pqr[i+1]]
    
    command = input()
    
    num_set = set(['1','2','3','4','5','6','7','8','9','0'])
    
    
    
    command_list = []
    i = 0;
    while i < len(command):
        if command[i] == 'M':
            i += 1
            tmp = ''
            while command[i] in num_set:
                tmp += command[i]
                i += 1
            command_list.append(tmp)   
        else:
            command_list.append(command[i])
            i += 1
    print(command_list)
    print(M_dict.items())
    
    # ( 만나면 재귀
    # ) 만나면 return p, r, idx 
    
    answer = 0
    
    def explore(idx=0):
        
        global answer
#         print(command_list[idx])
        first_m =  0
        mid_m = 0
        end_m = 0
        
        operation_matrix = []
        
        i = idx
        while i < len(command_list):
            if command_list[i] == '(':
                if len(operation_matrix) == 0:
                    first_m, mid_m, i = explore(i+1)
                    operation_matrix.append([first_m, mid_m])
                elif len(operation_matrix) == 1:
                    mid_m, end_m, i = explore(i+1)
                    operation_matrix.append([mid_m, end_m])
            elif  command_list[i] == ')':
                first_m = operation_matrix[0][0]
                mid_m = operation_matrix[0][1]
                end_m = operation_matrix[1][1]
                answer += first_m * mid_m * end_m
                return first_m , end_m , i              
                
            else:
                operation_matrix.append(M_dict[int(command_list[i])])
                if first_m:   
                    end_m = M_dict[int(command_list[i])][1]
                    mid_m = M_dict[int(command_list[i])][0]
                else:
                    mid_m = M_dict[int(command_list[i])][1]
                    first_m = M_dict[int(command_list[i])][0]
                
            i += 1
            
        
        
    explore()
    
    print(answer)
    
    tc -= 1

# 3
# 3
# 5 20 2 10
# ((M1M2)M3)
