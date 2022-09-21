#Fichier de création

#Silent pour echo:
.SILENT:

#Librairie a compiler pour l'app final


#Repertoire de tout les .o (Parfois en fichier Cacher)
bin = ./obj

#Application Final:
App:	$(*.o)
		echo Creation de App.app
		g++ main.cpp -o App.app

#Clean/Clear des .o et de l'application
clean:	
		rm $(*.o)
		rm ApplicHoraire.app
		clear

clear:	
		rm $(*.o)
		rm ApplicHoraire.app
		clear