pipeline {
    agent any
    stages {
        /*stage ('Checkout') {
            steps {
                checkout SCM
            }
        }*/
    
        stage ('Initialize') {
            steps {
                sh '''
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
    post {
        always {
            /*archiveArtifacts artifacts: 'bin/*.8xp', fingerprint: true*/
        }
    }
}