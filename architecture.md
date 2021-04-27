## Menu
- feed list of +ve people
- increment day
- make a person travel
- print list of +ve people
- print list of who all is in which city
- print all info about a specific person
- At city `S` who all are primary contacts of a covid +ve person
    - (It might not be the case that all people in the city `S` will be primary contacts of a covid positive person because: consider a case when a new person comes in who never interacted with the coid positive person. in that case that new person will be the secondary contact of that person)

## Structs and info
### Struct of a person contains:
- location (curreny city of residence)
- status (0 for OK, 1 for +ve)
- list of his primary contacts ==> this list will be of a struct containing `struct person` and the absolute date of meeting `int when_they_met`
- list of his secondary contacts ==> this list will be of a struct containing `struct person` and the absolte date of meeting`int when_they_met`
- the date quarantine_ends_on
- int risk_factor = {0,1,2}: (yes we do need this, read `Struct of a city` subheading) 
    - reason: in case a person X tests positive, then a person P who came into contact with X will be his primary contact, so P's risk factor will be 2
    - X's secondary contacts will have risk_factor 1
    - those people will have a risk factor of 0 if none of their primary or secondary conacts have gotten covid yet

### Struct of a city
- list of all people
- list of +ve people
- list of people whose risk_factor ==1 are counted as primary contacts of an infectee
- list of people who have risk_factor ==2 are counted as secondary contacts of an infectee
- its danger value
- in case adj list representation method is chosen: list of cities it connects to (linked list ints (becuase cities are identified by number))
    - using this way the array of `struct city` is all we need to store graphs, no need for building/maintaining/updating othe storage structure. 

## Setup
- For the graph: 
    - if the algo requires adj list representation, then array of (linked list of(city structs)), 
    - if the algo requires edge list format then array of( tuple of (city and danger value))
- maintain an array of people to deal with people related functions

## TODO
- [] implemenatation team to make linked list an easily usable data structure, preferably like a template: you tell that the linked list constructor to make a linked list of what data structure. Something like `list(int) l;` `list(person) personList;` etc.
- [] Graphs to be implemented as above
- [] array of persons 
- [] array of cities
- [] think of kth shortest path algo

## Misc
- empty as of now


