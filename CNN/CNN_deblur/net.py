from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import tensorflow as tf
import numpy as np
import re

from ops import *
from input_data import DataSet
import input_data
import time
from datetime import datetime
import os
import sys


class Net(object):
    def __init__(self, train=True, common_params=None, net_params=None):

        self.train = train
        self.weight_decay = 0.0

        if common_params:
            gpu_nums = len(str(common_params['gpus']).split(','))
            self.batch_size = int(int(common_params['batch_size']) / gpu_nums)
        if net_params:
            self.weight_decay = float(net_params['weight_decay'])

    def inference(self, data_input):

        # convolution layer 1
        conv_num = 1

        temp_conv = conv2d('conv' + str(conv_num), data_input, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 2
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 3
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 4
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 5
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 6
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 7
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 8
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 9
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 10
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 11
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 12
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 13
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 14
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, wd=self.weight_decay)
        conv_num += 1
        # 15
        temp_conv = conv2d('conv' + str(conv_num), temp_conv, [3, 3, 1, 64], stride=1, relu=False, wd=self.weight_decay)

        return temp_conv

    def loss(self, scope, model_conv, gt_image):

        flat_estimated = tf.reshape(model_conv, [-1, input_data.IMAGE_WIDTH])
        flat_gt_image = tf.reshape(gt_image, [-1, input_data.IMAGE_WIDTH])

        g_loss = tf.reduce_sum(tf.nn.l2_loss(flat_estimated - flat_gt_image)) / (self.batch_size)

        tf.summary.scalar('weight_loss', tf.add_n(tf.get_collection('losses', scope=scope)))

        #dl2c = tf.gradients(g_loss, flat_estimated)
        #dl2c = tf.stop_gradient(dl2c)

        return g_loss
