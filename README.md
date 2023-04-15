# userSwarm

Idea fragment for an interactive installation based on openframeworks to project user generated input 
- particles initially all round
- user can draw shapes
- user input options
	1. mouse
	2. movement tracking, e.g. 5s standing in reset area, turn drawing mode on/off
- user shapes are added to particle mix
	1. keep total amount of particles constant
	2. change color depending on collisions with user shapes
		i. color is a function of particle shape, shift from blue (=perfect circle) towards red for more pointy particles (= less like circle, larger range of radial range from center of mass)
- VR / AR in openframeworks
	1. handtracking 
	2. ultraleap
	3. leap motion tracking
