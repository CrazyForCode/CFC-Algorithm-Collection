class Individual {

    constructor(geneLength = 50) {
        this.genes = []
        this.genes.length = geneLength
    }

    generateIndividual() {
        for (let i = 0, length = this.genes.length; i < length; ++i) {
            this.genes[i] = Math.round(Math.random())
        }
    }

    getFitness() {
        return FitnessCalc.getFitness(this)
    }

    getGene(index) {
        return this.genes[index]
    }

    setGene(index, value) {
        this.genes[index] = value ? 1 : 0
    }

    size() {
        return this.genes.length
    }

    toString() {
        return this.genes.reduce((previous, current) => {
            return previous + current
        }, '')
    }
}

module.exports = Individual
let FitnessCalc = require('./FitnessCalc');