# 1. AP4A - Projet : Rendu final

## 1.1. Contexte

Ce programme permet de simuler l'écosystème de capteurs interne d'un avion de ligne. Quatre types de capteurs sont mis en relation avec un serveur par l'intermédiaire d'un scheduler :
  - Capteur de température
  - Capteur d'humidité
  - Capteur de pression
  - Capteur de lumière

## 1.2. Mise en situation

Le scheduler récupère, à un intervalle de temps donné (variant suivant le type de capteur), les informations générées par les capteurs pour les transmettre au serveur. Ce dernier va logger les informations dans des fichiers ou/et les afficher dans la console.

Les capteurs génèrent les informations dimensionnées pour s'approcher au plus de la réalité :
  - Température moyenne de 23°C avec une dispertion de 3°C
  - Humidité idéale de 20% avec une dispertion de 8%
  - Pression moyenne de 79289 Pa avec une dispertion de 3447 Pa
  - Intensité lumineuse correspondant à un booléen

## 1.3. Utilisation du programme

Le ficher exécutable se trouvera dans un dossier nommé Simulation. (Les logs des mesures se trouveront dans le même dossier si le programme à été lancé depuis celui-ci.)

Le programme fonctionne indéfiniment jusqu'à ce que l'utilisateur entre la lettre "q" dans la console (une latence peut se faire ressentire le temps que tous les threads se synchronisent).

/!\ L'entrée dans la console peut être ignorée par le programme si un cout est réalisé avant la pression de la touche Entrée. Il sera par conséquent nécessaire d'entrer à nouveau "q"+Entrée dans la console.

## 1.4. Crédits

Cette implémentation de la simulation d'un écosystème de capteur à été réalisée dans l'UV AP4A, au cours du semestre d'Automne 2022. <br>
Auteur : Flavian THEUREL