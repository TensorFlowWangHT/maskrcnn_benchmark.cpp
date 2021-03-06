#include <roi_align.h>

namespace rcnn {
namespace layers {

ROIAlignImpl::ROIAlignImpl(std::pair<int64_t, int64_t> output_size, double spatial_scale, int64_t sampling_ratio)
                          : pooled_height_(std::get<0>(output_size)),
                            pooled_width_(std::get<1>(output_size)),
                            spatial_scale_(spatial_scale),
                            sampling_ratio_(sampling_ratio) {}

std::shared_ptr<ROIAlignImpl> ROIAlignImpl::clone(torch::optional<torch::Device> device) const{
  std::shared_ptr<ROIAlignImpl> copy = std::make_shared<ROIAlignImpl>(std::make_pair(pooled_height_, pooled_width_), spatial_scale_, sampling_ratio_);
  return copy;
}

torch::Tensor ROIAlignImpl::forward(const torch::Tensor& x, torch::Tensor rois){
  return _ROIAlign::apply(x, rois, pooled_height_, pooled_width_, spatial_scale_, sampling_ratio_);
}

} // namespace layers
} // namespace rcnn
