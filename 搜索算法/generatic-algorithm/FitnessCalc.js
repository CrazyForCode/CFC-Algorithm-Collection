class FitnessCalc {
    static setSolution(solution) {
        FitnessCalc.solution = [...solution].map(value => +value)
    }

    static setValues(values) {
        FitnessCalc.values = values
    }

    static setVolumes(volumes) {
        FitnessCalc.volumes = volumes
    }

    static setMaxVolumes(value) {
        FitnessCalc.maxVolume = value
    }

    static getFitness(individual) {
        let volume = 0
        let value = 0

        for (let i = 0; i < individual.size(); ++i) {
            if (individual.getGene(i) === 1) {
                volume += FitnessCalc.volumes[i]
            }
        }

        if (volume > 1000) {
            return -1
        }

        for (let i = 0; i < individual.size(); ++i) {
            if (individual.getGene(i) === 1) {
                value += FitnessCalc.values[i]
            }
        }

        return value
    }

    static getMaxFitness() {
        return FitnessCalc.maxVolume
    }
}

module.exports = FitnessCalc
var Individual = require('./Individual')