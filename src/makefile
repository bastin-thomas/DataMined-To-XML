#Fichier de création

#Silent pour echo:
.SILENT:

#Librairie a compiler pour l'app final


#Repertoire de tout les .o (Parfois en fichier Cacher)
*.o = $(bin)/Film.o $(bin)/Genre.o
bin = ./obj
LibFilm = ./Film
LibGenre = ./Film/Genre

#Application Final:
App:	main.cpp $(*.o)
		echo Creation de App.app
		g++ main.cpp $(*.o) -o App.app

$(bin)/Film.o:	$(LibFilm)/film.cpp $(LibFilm)/film.hpp
		echo Creation de Film.o
		g++ $(LibFilm)/film.cpp -c -o $(bin)/Film.o

$(bin)/Genre.o:	$(LibGenre)/genre.cpp $(LibGenre)/genre.hpp
		echo Creation de Genre.o
		g++ $(LibGenre)/genre.cpp -c -o $(bin)/Genre.o

#Clean/Clear des .o et de l'application
clean:	
		rm $(*.o)
		rm ApplicHoraire.app
		clear

clear:	
		rm $(*.o)
		rm ApplicHoraire.app
		clear