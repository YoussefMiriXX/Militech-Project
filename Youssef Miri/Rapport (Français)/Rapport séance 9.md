# <p align="center"><ins> Rapport Séance 9
##### 14 Février 2024
### <ins>Résumé:
La séance d'aujourd'hui a été consacrée au transfert de programmes déjà réalisés sur un ordinateur personnel vers la Jetson Nano et assurer le bon fonctionnement des programmes.

### <ins> Déroulement de la séance:

La séance s'est déroulée avec succès et les programmes ont été transférés avec succès sur la Jetson Nano.
Par contre, les perfermances de la jetson était beaucoup plus limités que l'ordianteur déjà utilisé.

Après plusieurs recherches, j'ai trouvé que la Jetson utilise son processeur pour faire fonctionner le programme mais ce dernier est beaucoup moins puissant que celui de l'ordinateur en exucutant le programme pour la reconnaissance faciale je peux avoir un fps compris entre 10 et 20 ce qui est insuffisant pour avoir un robot performant.
Alors, l'utilisation du GPU de la Jetson est nécessaire pour avoir un bon rendement.

### <ins> Configuration de la Jetson:
Malgré que le but principal de la jetson est de faire fonctionner les application du deep learning et l'intelligence artificielle, la jetson utilise jamais son GPU qui est plus puissant que son processeur.

###### une configuration de la jetson est nécessaire pour qu'elle utilise son GPU.

Le but est de télécharger les librairies `CUDA` qui permettent à `Opencv` de fonctionner en utilisant le GPU de la Jetson.

### <ins> Étapes Suivies:

Le téléchargement de `CUDA`nécessite l'installation de plusieurs dépendances logicielles pour fonctionner correctement ce qui peut prendre entre 2 et 3 heures.

#### <ins>Étape 1: JTOP

JTOP est un outil de surveillance système fournissant des informations en temps réel sur les performances de Jetson. Il affiche des informations sur l'utilisation du CPU, du GPU, de la mémoire et d'autres ressources système. JTOP affiche la sortie des moniteurs de puissance Jetson et des capteurs de température.

```
sudo apt update
sudo apt install python3-pip
sudo pip3 install -U jetson-stats
sudo reboot
jtop
```
#### <ins>Étape 2:Créer un swap file.
Un swap file nous permet d'avoir plus de mémoire sur la Jetson cela est important pour télécharger les dépendances sans problèmes.
On peut avoir environ 6 Gb de mémoire au lieu de 4.

```
sudo fallocate -l 4G /var/swapfile 

sudo chmod 600 /var/swapfile

 sudo mkswap /var/swapfile

 sudo swapon /var/swapfile

 sudo bash -c 'echo "/var/swapfile swap swap defaults 0 0"  >> /etc/fstab’ 
```
#### <ins> Étape 3: Téléchargement les dépendances avant OpenCV avec Cuda.

```
sudo sh -c "echo '/usr/local/cuda/lib64' >> /etc/ld.so.conf.d/nvidia-tegra.conf“

sudo ldconfig

sudo apt-get install build-essential cmake git unzip pkg-config

sudo apt-get install libjpeg-dev libpng-dev libtiff-dev

sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev

sudo apt-get install libgtk2.0-dev libcanberra-gtk*

sudo apt-get install python3-dev python3-numpy python3-pip

sudo apt-get install libxvidcore-dev libx264-dev libgtk-3-dev

sudo apt-get install libtbb2 libtbb-dev libdc1394-22-dev

sudo apt-get install libv4l-dev v4l-utils

sudo apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev

sudo apt-get install libavresample-dev libvorbis-dev libxine2-dev

sudo apt-get install libfaac-dev libmp3lame-dev libtheora-dev

sudo apt-get install libopencore-amrnb-dev libopencore-amrwb-dev

sudo apt-get install libopenblas-dev libatlas-base-dev libblas-dev

sudo apt-get install liblapack-dev libeigen3-dev gfortran

sudo apt-get install libhdf5-dev protobuf-compiler

sudo apt-get install libprotobuf-dev libgoogle-glog-dev libgflags-dev
```
#### <ins> Étape 4:Télécharger OpenCV.
```
cd ~
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.5.1.zip 
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.5.1.zip 
unzip opencv.zip 
unzip opencv_contrib.zip

Now rename the directories. Type each command below, one after the other.
mv opencv-4.5.1 opencv
mv opencv_contrib-4.5.1 opencv_contrib
rm opencv.zip
rm opencv_contrib.zip

Lets build OpenCV now:
cd ~/opencv
mkdir build
cd build
 ```

 #### <ins>Étape 5: Télécharger les dépendances.
 ```
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules -D EIGEN_INCLUDE_PATH=/usr/include/eigen3 -D WITH_OPENCL=OFF -D WITH_CUDA=ON -D CUDA_ARCH_BIN=5.3 -D CUDA_ARCH_PTX="" -D WITH_CUDNN=ON -D WITH_CUBLAS=ON -D ENABLE_FAST_MATH=ON -D CUDA_FAST_MATH=ON -D OPENCV_DNN_CUDA=ON -D ENABLE_NEON=ON -D WITH_QT=OFF -D WITH_OPENMP=ON -D WITH_OPENGL=ON -D BUILD_TIFF=ON -D WITH_FFMPEG=ON -D WITH_GSTREAMER=ON -D WITH_TBB=ON -D BUILD_TBB=ON -D BUILD_TESTS=OFF -D WITH_EIGEN=ON -D WITH_V4L=ON -D WITH_LIBV4L=ON -D OPENCV_ENABLE_NONFREE=ON -D INSTALL_C_EXAMPLES=OFF -D INSTALL_PYTHON_EXAMPLES=OFF -D BUILD_NEW_PYTHON_SUPPORT=ON -D BUILD_opencv_python3=TRUE -D OPENCV_GENERATE_PKGCONFIG=ON -D BUILD_EXAMPLES=OFF ..
```

Après téléchargement, il faut juste taper dans le terminal `make -j4`
pour commencer l'installation qui peut durer pour 2 heures.

#### <ins> Etape 6:finir l'intallation:
```cd ~
sudo rm -r /usr/include/opencv4/opencv2
cd ~/opencv/build
sudo make install
sudo ldconfig
make clean
sudo apt-get update 

Verify OpenCV Installation
#open python3 shell
python3
import cv2
cv2._version_
```

### <ins> Conclusion:

L'utilisation de CUDA avec la jetson prend beaucoup de temps pour bien fonctionner et on peut rencontrer beaucoup de problèmes pendant l'installation.

Le test des performence se fait dans la séance suivante.
