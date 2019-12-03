
def recurs(exemple,dic,dic_id) : 

	return dic[dic_id].recurs(exemple)

def noreturn(obj) : 
	return obj
if __name__ == '__main__':
	
	exemple = {"salut":"toi"}
	dic = {"salut": "copain"}
	dic_id = 0

	# jsp = recurs(exemple,dic,dic_id)
	exemple.noreturn(obj)