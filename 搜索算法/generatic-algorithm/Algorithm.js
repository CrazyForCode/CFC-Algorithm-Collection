class Algorithm {

    static init() {
        Algorithm.uniformRate = .5
        Algorithm.mutationRate = .015
        Algorithm.tournamentSize = 5
        Algorithm.elitism = true
    }

    static evolvePopulation(pop) {
        let newPopulation = new Population(false)
        if (Algorithm.elitism) {
            newPopulation.saveIndividual(0, pop.getFittest())
        }

        let offset = Algorithm.elitism ? 1 : 0
        for (let i = offset, length = pop.individuals.length; i < length; ++i) {
            let individual1 = Algorithm.tournamentSelection(pop)
            let individual2 = Algorithm.tournamentSelection(pop)
            let newIndividual = Algorithm.crossover(individual1, individual2)

            newPopulation.saveIndividual(i, newIndividual)
        }

        for (let i = offset, size = newPopulation.individuals.length; i < size; ++i) {
            Algorithm.mutate(newPopulation.getIndividual(i))
        }

        return newPopulation
    }

    static mutate(individual) {
        for (let i = 0, size = individual.size(); i < size; ++i) {
            if (Math.random() <= Algorithm.mutationRate) {
                individual.setGene(i, Math.round(Math.random()))
            }
        }
    }

    static crossover(individual1, individual2) {
        let newIndividual = new Individual()

        for (let i = 0; i < individual1.size(); ++i) {
            if (Math.random() <= Algorithm.uniformRate) {
                newIndividual.setGene(i, individual1.getGene(i))
            } else {
                newIndividual.setGene(i, individual2.getGene(i))
            }
        }

        return newIndividual
    }

    static tournamentSelection(pop) {
        let individuals = []
        individuals.length = Algorithm.tournamentSize

        let tournamentPopulation = new Population(false, individuals)
        for (let i = 0; i < Algorithm.tournamentSize; ++i) {
            let id = Math.floor(Math.random() * pop.individuals.length)
            tournamentPopulation.saveIndividual(i, pop.getIndividual(id))
        }

        return tournamentPopulation.getFittest()
    }
}

module.exports = Algorithm
let Population = require('./Population'),
    Individual = require('./Individual')