# Progetto Pick and Delivery 

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

### Overview
Il progetto offre un sistema di pick and delivery gestito da un robot mobile all'interno di una determinata mappa. Il tutto realizzato attraverso un client e un server, in particolare:
- Il primo client si occupa di fornire all'utente attraverso un terminale, un sistema _Picker_ che prende in input un _goal (x , y , theta)_, rappresentante la posizione dove prelevare il pacco, in seguito una volta arrivato, il robot  chiede conferma di aver caricato correttamente il pacco; una volta ricevuta la conferma, verrà chiesto di fornire un nuovo _goal (x , y , theta)_ rappresentante la posizione di consegna. Un secondo client fornisce un sistema di tipo _Deliver_  che, una volta arrivato il robot a destinazione invierà una conferma di aver ricevuto correttamente il pacco.
- Il server si occupa di comunicare con i nodi adibiti allo spostamento del robot i goal che riceve dal client, calcolando inoltre attraverso un sistema interno lo stato di avanzamento all'interno della mappa (es : bloccato, in movimento, arrivato a destinazione).
- 
### Usage

Lanciare i nodi/programmi ROS necessari attraverso SRRG Web Controller: 
```
 _roscore
 _stage
 _mapserver
 _rviz
 _localize
 _planner
 _follower(static o dinamic)
```

> Nota: Localizzare su rviz il robot all'interno della mappa

Aprire un primo terminale  ed eseguire il picker client

``` sh
cd prog_ws
source ./devel/setup.bash
rosrun prog_pkg picker
``` 
Aprire un secondo terminale ed eseguire il deliver client 

``` sh
cd prog_ws
source ./devel/setup.bash
rosrun prog_pkg deliver
``` 

Aprire un terzo terminale ed eseguire il server

``` sh
cd prog_ws
source ./devel/setup.bash
rosrun prog_pkg set_goal
``` 
A questo punto seguire le istruzioni che compaiono sui tabs del terminale e controllare lo stato di avanzamento del robot in rviz e/o stage.