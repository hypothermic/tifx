pipeline {
    agent any
    environment {
        PATH = "/opt/CEdev/bin:$PATH"
        CEDEV= "/opt/CEdev"
    }
    stages {
        /*stage ('Checkout') {
            steps {
                checkout SCM
            }
        }*/
    
        stage ('Initialize') {
            steps {
                /* Temporarily add exports to the initialize, in case environment{} didn't work */
                sh '''
                    export CEDEV=/opt/CEdev
                    export PATH=/opt/CEdev/bin:$PATH
                    make clean
                '''
            }
        }
        
        /*stage ('Tests') {
            steps {
                sh 'mvn test' 
            }
        }*/

        stage ('Build') {
            steps {
                sh 'make debug' 
            }
        }
    }
    /*post {
        always {
            archiveArtifacts artifacts: 'bin/*.8xp', fingerprint: true
        }
    }*/
}