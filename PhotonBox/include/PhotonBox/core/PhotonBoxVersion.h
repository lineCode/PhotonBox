#ifndef PHOTON_BOX_VERSION_H
#define PHOTON_BOX_VERSION_H

#define PHOTON_BOX_APPLICATION_NAME "PhotonBox Engine"
#define PHOTON_BOX_VERSION_MAJOR 0
#define PHOTON_BOX_VERSION_MINOR 7
#define PHOTON_BOX_VERSION_PATCH 1
#define PHOTON_BOX_VERSION_BUILD 1285

#define TO_STR2(x) #x
#define TO_STR(x) TO_STR2(x)
#define PHOTON_BOX_VERSION (PHOTON_BOX_APPLICATION_NAME " " TO_STR(PHOTON_BOX_VERSION_MAJOR) "." TO_STR(PHOTON_BOX_VERSION_MINOR) "." TO_STR(PHOTON_BOX_VERSION_PATCH) ":" TO_STR(PHOTON_BOX_VERSION_BUILD))

#endif // PHOTON_BOX_VERSION_H