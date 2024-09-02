pipeline {
    agent any

    stages {
        stage('Development') {
            steps {
                echo 'Hello Dev'
                bat 'git clone https://github.com/Manash-Sangam/Codeforces.git'
            }
        }
        stage('QA') {
            steps {
                echo 'Hello QA'
            }
        }
        stage('UAT') {
            steps {
                echo 'Hello UAT'
            }
        }
        stage('Pre-Prod') {
            steps {
                echo 'Hello Pre-Prod'
            }
        }
        stage('Prod') {
            steps {
                echo 'Hello Prod'
            }
        }
    }
}
