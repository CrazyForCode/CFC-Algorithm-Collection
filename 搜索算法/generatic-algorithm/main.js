let FitnessCalc = require('./FitnessCalc')
Individual = require('./Individual')
Population = require('./Population')
Algorithm = require('./Algorithm')
Algorithm.init()

let newPopulation = new Population(true),
    generationCount = 0

FitnessCalc.setMaxVolumes(1000)
FitnessCalc.setVolumes([80, 82, 85, 70, 72, 70, 66, 50, 55, 25,
    50, 55, 40, 48, 50, 32, 22, 60, 30, 32,
    40, 38, 35, 32, 25, 28, 30, 22, 50, 30,
    45, 30, 60, 50, 20, 65, 20, 25, 30, 10,
    20, 25, 15, 10, 10, 10, 4, 4, 2, 1
])

FitnessCalc.setValues([220, 208, 198, 192, 180, 180, 165, 162, 160, 158,
    155, 130, 125, 122, 120, 118, 115, 110, 105, 101,
    100, 100, 98, 96, 95, 90, 88, 82, 80, 77,
    75, 73, 72, 70, 69, 66, 65, 63, 60, 58,
    56, 50, 30, 20, 15, 10, 8, 5, 3, 1
])

while (generationCount < 20) {
    console.log('Generation: ' + generationCount++ + ' Fittest: ' + newPopulation.getFittest().getFitness())
    newPopulation = Algorithm.evolvePopulation(newPopulation)
}