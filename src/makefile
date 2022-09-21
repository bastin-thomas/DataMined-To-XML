#Fichier de création

#Silent pour echo:
.SILENT:

#Librairie a compiler pour l'app final


#Repertoire de tout les .o (Parfois en fichier Cacher)
*.o = $(bin)/Film.o
bin = ./obj
LibFilm = ./Film

#Application Final:
App:	main.cpp $(*.o)
		echo Creation de App.app
		g++ main.cpp $(*.o) -o App.app

$(bin)/Film.o:	$(LibFilm)/film.cpp $(LibFilm)/film.h
		echo Creation de film.o
		g++ $(LibFilm)/film.cpp -c -o $(bin)/Film.o

#Clean/Clear des .o et de l'application
clean:	
		rm $(*.o)
		rm ApplicHoraire.app
		clear

clear:	
		rm $(*.o)
		rm ApplicHoraire.app
		clear