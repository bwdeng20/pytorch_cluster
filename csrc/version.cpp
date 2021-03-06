#include <Python.h>
#include <torch/script.h>

#ifdef WITH_CUDA
#include <cuda.h>
#endif

#ifdef _WIN32
PyMODINIT_FUNC PyInit__version(void) { return NULL; }
#endif

int64_t cuda_version() {
#ifdef WITH_CUDA
  return CUDA_VERSION;
#else
  return -1;
#endif
}

static auto registry =
    torch::RegisterOperators().op("torch_cluster::cuda_version", &cuda_version);
