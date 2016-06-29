class Population {
    constructor(initialise, individuals) {
        if (!individuals) {
            this.individuals = []
            this.individuals.length = 60
        } else {
            this.individuals = []
        }

        if (initialise) {
            for (let i = 0, length = this.individuals.length; i < length; ++i) {
                let newIndividual = new Individual()
                for (let j = 0; j < newIndividual.size(); ++j) {
                    newIndividual.setGene(j, 0)
                }

                this.saveIndividual(i, newIndividual)
            }
        }
    }

    getIndividual(index) {
        return this.individuals[index]
    }

    getFittest() {
        let tmp = this.individuals.reduce((previous, current) => {
            if (previous.getFitness() >= current.getFitness()) {
                return previous
            } else {
                return current
            }
        }, this.individuals[0])

        return tmp
    }

    saveIndividual(index, individual) {
        this.individuals[index] = individual
    }
}

module.exports = Population
let Individual = require('./Individual')